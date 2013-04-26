using System;
using System.Threading;
using System.Windows;
using System.Windows.Markup;
using System.IO;

namespace org.oha7.dotnet
{
    public class WpfWin : System.Windows.Window
    {
        private DependencyObject rootObject;

        public DependencyObject Load(String xaml)
        {
            try
            {
                System.Reflection.Assembly assembly = System.Reflection.Assembly.GetExecutingAssembly();
                String path = System.IO.Path.GetDirectoryName(assembly.Location);
                path += "\\" + xaml;
                StreamReader mysr = new StreamReader(path);

                rootObject = XamlReader.Load(mysr.BaseStream) as DependencyObject;
                this.Content = rootObject;

            }
            catch (FileNotFoundException ex)
            {
                MessageBox.Show(ex.Message.ToString());
            }
            return rootObject;
        }

        public DependencyObject get(String path)
        {
            return LogicalTreeHelper.FindLogicalNode(rootObject, path);
        }

    }

    public class WpfApp : System.Windows.Application
    {
        private WpfWin win = new WpfWin();

        public DependencyObject Load(String path)
        {
            DependencyObject o = win.Load(path);
            if (o == null)
                this.Shutdown();
            return o;
        }

        public DependencyObject get(String path)
        {
            return win.get(path);
        }

        public void run()
        {
            win.Show();
            win.Activate();
        }

        public void close()
        {
            Application.Current.Shutdown();
//            win.Close();
        }
    }

    public class WPFLauncher
    {
        private volatile WpfApp app;
        private Thread thread;
        private DependencyObject root;

        private delegate DependencyObject AppLoad(string xaml);
        private delegate void AppRun();
        private delegate void AppShutdown();
        private delegate void AppClose();
        private delegate DependencyObject AppGet(string xaml);

        public WPFLauncher()
        {
            start();
        }

        public DependencyObject load(String path)
        {
            root = (DependencyObject)app.Dispatcher.Invoke(new AppLoad(app.Load), path);
            return root;
        }

        public void exit()
        {
            if (app != null)
            {
               // app.Dispatcher.Invoke(new AppShutdown(app.Shutdown), null);
                app.Dispatcher.BeginInvoke(new AppClose(app.close), null);
            }
        }

        public void run()
        {
            if (app == null)
                return;

            app.Dispatcher.Invoke(new AppRun(app.run), null);
            thread.Join();
        }

        public DependencyObject get(String n)
        {
            if (app == null)
                return null;

            return (DependencyObject)app.Dispatcher.Invoke(new AppGet(app.get), n);
        }

        private void start()
        {
            thread = new Thread(new ThreadStart(this.worker_run));
            thread.SetApartmentState(ApartmentState.STA);
            thread.Start();
            while (app == null)
            {
                Thread.Sleep(100);
            }
        }

        private void worker_run()
        {
            app = new WpfApp();
            app.Run();
        }
    }
}
