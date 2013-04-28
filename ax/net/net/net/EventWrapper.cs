using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace org.oha7.dotnet
{
    class EventWrapper : MarshalByRefObject
    {
        private Object handler;
        public delegate void EventHandler(object sender, EventArgs e);

        public EventWrapper( Object h)
        {
            handler = h;
        }

        public void eventMethod(object sender, EventArgs e)
        {
            Object[] args = wrapArgs(new Object[] { sender, e } );
            handler.GetType().InvokeMember("", System.Reflection.BindingFlags.InvokeMethod, null, handler , args);
        }

        private Object[] wrapArgs(Object[] args)
        {
            if (args == null || args.Length == 0)
                return args;

            int len = args.Length;
            for (int i = 0; i < len; i++)
            {
                
                args[i] = new RefWrapper(args[i]);
            }
            return args;
        }
    }
}
