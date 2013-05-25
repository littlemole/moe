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
            Object[] args = RefWrapper.wrap(new Object[] { sender, e } );
            handler.GetType().InvokeMember("", System.Reflection.BindingFlags.InvokeMethod, null, handler , args);
        }
    }
}
