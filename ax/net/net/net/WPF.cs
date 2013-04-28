using System;
using System.Threading;
using System.Windows;
using System.Windows.Markup;
using System.IO;

namespace org.oha7.dotnet
{
    public class XAML
    {
        public Application application = new Application();
        public Window window = new Window();

        private DependencyObject rootObject;

        private delegate void WindowClose();

        public void run()
        {
            window.Show();
            window.Activate();
            application.Run();
        }

        public void exit()
        {
            application.Dispatcher.BeginInvoke(new WindowClose(window.Close), null);
        }

        public DependencyObject load(String xaml)
        {
            try
            {
                String path = xaml;
                if (!System.IO.File.Exists(xaml))
                {
                    System.Reflection.Assembly assembly = System.Reflection.Assembly.GetExecutingAssembly();
                    path = System.IO.Path.GetDirectoryName(assembly.Location);
                    path += "\\forms\\" + xaml;
                }

                StreamReader mysr = new StreamReader(path);

                rootObject = XamlReader.Load(mysr.BaseStream) as DependencyObject;
                window.Content = rootObject;

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
}
