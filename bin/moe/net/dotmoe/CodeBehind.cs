using System;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Reflection;
using System.Collections;
using mshtml;


namespace mol
{
    public class CodeBehind : MarshalByRefObject
    {
        //////////////////////////////////////////////////////////////////
        /// Constructor sets references and attaches an unload event
        /// handler for cleanup. A back reference is provided back
        /// to the hosting app to enable scripts to call into .NET
        /// yes, this will work
        //////////////////////////////////////////////////////////////////

        public CodeBehind()
        {
            // get COM references to moe and to HTMLframe   
            this.moe   = mol.External<Moe.IXmoe>.obj("moe");
            this.frame = mol.External<Moe.IMoeFrame>.obj("frame");

            // get HTML Document interfaces and HTML wnd interface
	        this.doc2  = (IHTMLDocument2)(this.frame.Document);
	        this.doc3  = (IHTMLDocument3)(this.frame.Document);
	        this.wnd   = (IHTMLWindow2)  (this.doc2.parentWindow);

            // Attach unload handler for cleanup
            AddEvent<HTMLWindowEvents2_Event>(this.wnd, "onunload", this.OnFormClose);
    	            
            // inspect HTMLEvent Attributes in derived class

            // get all public methods
            MethodInfo[] mi = this.GetType().GetMethods(BindingFlags.Instance |BindingFlags.FlattenHierarchy| BindingFlags.Public);

            foreach( MethodInfo m in mi )
            {
                // get HTML event attributes (assuming one)
                Attribute[] atts = (Attribute[])m.GetCustomAttributes(typeof(HTMLEventHandlerAttribute), true);

                HTMLEventHandlerAttribute[] hatts = (HTMLEventHandlerAttribute[])atts;
                foreach (HTMLEventHandlerAttribute att in hatts)
                {
                    // split the methodname on "_" as per convention
                    // first part of methodname considered HTML id attribute
                    // of DOM element to connect to, and second part of
                    // methodname considered HTML eventname. example:
                    // button_onclick 

                    string methodName = m.Name;
                    string[] mn = methodName.Split( new string[] {"_"}, StringSplitOptions.RemoveEmptyEntries);
                    if (mn.Length < 2)
                        continue;

                    string dom_id    = mn[0];
                    string eventname = mn[1];

                    // get HTML element node to attach event handler to
                    object el = this.doc3.getElementById(dom_id);
                    if (el == null)
                        continue;

                    // bind event
                    this.BindEvent(att.EventType, el, eventname, m);
                }
            }    
            this.frame.CodeBehind = this;
	    }

        //////////////////////////////////////////////////////////////////
        // cleanup
        //////////////////////////////////////////////////////////////////

        public virtual void unload()
        {	  
        }

        //////////////////////////////////////////////////////////////////
        // scripting support for string eval-utation as well as 
        // typed calls (invoke) of script functions
        //////////////////////////////////////////////////////////////////

        public bool invoke( string script, object[] args )
        {
		    this.frame.Scripts.GetType()
		        .InvokeMember( script, 
				    		   System.Reflection.BindingFlags.InvokeMethod,
					    	   null,
						       this.frame.Scripts,
                               args );
            return false;
        }

        public bool eval(string script, string lang)
        {
            this.frame.Eval(script, lang);
            return false;
        }

        public bool eval(string script)
        {
            this.frame.Eval(script, "");
            return false;
        }

        //////////////////////////////////////////////////////////////////
        // DOM Accessor, giving IHTMLElement interface
        //////////////////////////////////////////////////////////////////

        public IHTMLElement this[string id]
        {
            get{
                return this.doc3.getElementById(id);
            }
        }

        //////////////////////////////////////////////////////////////////
        // generic access, Interface to be provided
        //////////////////////////////////////////////////////////////////

        public T node<T>(string id)
        {
            return (T)this.doc3.getElementById(id);
        }

        //////////////////////////////////////////////////////////////////
        // DOM event handling support
        //////////////////////////////////////////////////////////////////

        public delegate bool bEventDelegate(mshtml.IHTMLEventObj e);
        public delegate void voidEventDelegate(mshtml.IHTMLEventObj e);
       
        public void bAddEvent<E>(object el, string eventname, bEventDelegate handler)
        {
            BindEvent(typeof(E), el, eventname, handler);
        }

        public void AddEvent<E>(object el, string eventname, voidEventDelegate handler)
        {
            BindEvent(typeof(E), el, eventname, handler);
        }
        
        //////////////////////////////////////////////////////////////////
        // default event attach helpers, giving HTMLElementEvents2_Event
        //////////////////////////////////////////////////////////////////

        public void bAddEvent(object el, string eventname, bEventDelegate handler)
        {
            BindEvent(typeof(HTMLElementEvents2_Event), el, eventname, handler);
        }

        public void AddEvent(object el, string eventname, voidEventDelegate handler)
        {
            BindEvent(typeof(HTMLElementEvents2_Event), el, eventname, handler);
        }
      
        //////////////////////////////////////////////////////////////////
        // DOM event handling impl
        //////////////////////////////////////////////////////////////////

        private void BindEvent(Type EventType, object el, string eventname, Delegate handler)
        {
            // convert function pointer for mshtml            
            uint uptr = (uint)handler.Method.MethodHandle.GetFunctionPointer();
            UIntPtr ptr = new UIntPtr(uptr);

            BindEventImpl(EventType, el, eventname, ptr);
        }

        private void BindEvent(Type EventType, object el, string eventname, MethodInfo m)
        {
            // convert function pointer for mshtml            
            uint uptr   = (uint)m.MethodHandle.GetFunctionPointer();
            UIntPtr ptr = new UIntPtr(uptr);

            BindEventImpl(EventType, el, eventname, ptr);
        }

        private void BindEventImpl(Type EventType, object el, string eventname, UIntPtr ptr)
        {
            //cache interface or loose event handler after first usage
            this.events.Add(el);

            // determine event handler wrapper type            
            EventInfo ei = EventType.GetEvent(eventname);
            Type HandlerType = ei.EventHandlerType;

            // create handler wrapper
            object h = Activator.CreateInstance(HandlerType, this, ptr);

            // attach to element event interface
            ei.AddEventHandler(el, (Delegate)h);
        }
        //////////////////////////////////////////////////////////////////
        // Unload implementation. will call unload() to allow custom
        // user cleanup
        //////////////////////////////////////////////////////////////////

        private void OnFormClose(mshtml.IHTMLEventObj pEvtObj)
        {
            Marshal.ReleaseComObject(this.frame);
            Marshal.ReleaseComObject(this.moe);
            this.unload();
            Application.Exit();
        }

        //////////////////////////////////////////////////////////////////
        // members
        //////////////////////////////////////////////////////////////////

        protected Moe.IXmoe                         moe;
	    protected Moe.IMoeFrame                     frame;
        protected mshtml.IHTMLWindow2               wnd;
        protected mshtml.IHTMLDocument2             doc2;
        protected mshtml.IHTMLDocument3             doc3;
        protected mshtml.HTMLWindowEvents2_Event    wndEvent;

        private ArrayList events = new ArrayList();
    }

    [AttributeUsage(AttributeTargets.Method, Inherited=true, AllowMultiple=true)]
    public class HTMLEventHandlerAttribute : Attribute 
    {
        public HTMLEventHandlerAttribute(Type type)
        {
            event_type = type;
        }

        public Type EventType
        {
            get { return event_type; }
        }

        private Type event_type;
    }
}
