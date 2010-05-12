package mol;

import mol.HtmlEvent;
 
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import mol.mshtml.events.HTMLWindowEvents2;
import com4j.*;
import mol.moe.*;
import mol.mshtml.*;

/**
 * Base class CodeBehind for HTML Form based moe extensions.
 */
@IID("{F73BED73-D189-4885-919C-9879D51F413B}")

public class CodeBehind implements IMoeExtension { //, Runnable  {
	
	public CodeBehind() {
		
	}
	
	/** init - called from moe on startup after constructor call
	 * as a phase second constructor. 
	 * @see mol.moe.IMoeExtension#init(int, int)
	 */
	@SuppressWarnings("unchecked")
	@Override 
	public void init( int m, int f) { 

		// retrieve moe native reference
		if ( m != 0) {
			Com4jObject disp = COM4J.getInterfaceFromGIT(Com4jObject.class, m);
			moe = disp.queryInterface(IXmoe.class);
		}

		// retrieve HTML frame native reference		
		if ( f != 0 ) {
			Com4jObject disp = COM4J.getInterfaceFromGIT(Com4jObject.class, f);
			frame = disp.queryInterface(IMoeFrame.class);

			if ( frame != null ) {
				// prefetch and cache some interesting COM interfaces
				Com4jObject obj = this.frame.document();
				this.doc2 = obj.queryInterface(IHTMLDocument2.class);
				//this.doc2 = this.frame.document();
				this.doc3 = this.doc2.queryInterface(IHTMLDocument3.class);
				this.wnd  = this.doc2.parentWindow();								
			}
							
			// hook the HTML window unonload event - see event handler below
			attach("onunload",wnd);
			
			
			// walk derived class fields - attach Interface handlers
			Class clazz = this.getClass();			
			java.lang.reflect.Field[] fields = clazz.getFields();
			for ( int i = 0; i < fields.length; i++ ) {
				
				// scan for HtmlEvent Annotations
				HtmlEvent event = (HtmlEvent)(fields[i].getAnnotation(HtmlEvent.class));
				if ( event != null ) {
					
					// retrieve DOM element to hook event to 
					String id = event.value();
					IHTMLElement element = this.doc3.getElementById(id);
					
					// determine concrete element type of event src
					Class<com4j.Com4jObject> type = (Class<com4j.Com4jObject>)event.type();
					com4j.Com4jObject o = element.queryInterface(type);
					
					// get name of event handler
					String name = fields[i].getName();
					
					// attach the event handler to src
					attach(name, o );
				}
			}		
			
			
			// walk derived class methods - connect MSHTML style DISPID(0) handlers
			Method[] methods = clazz.getMethods();
			for ( int i = 0; i < methods.length; i++ ) {
				DOMEvent event = (DOMEvent)(methods[i].getAnnotation(DOMEvent.class));
				if ( event == null ) 
					continue;

				String id = event.value();			
				String name = methods[i].getName();
			
				Class<com4j.Com4jObject> type = (Class<com4j.Com4jObject>)event.type();			

				connect(name,id,this,type);
			}
			
		}
		// call derived class override, if any, for initialization
		this.load();				
	}
	
	public void load() {
		
	}
	
	public void unload() {
		
	}
	

	/**
	 *  HTML Window onunload handler - tears down the app
	 */
	public HTMLWindowEvents2 onunload = new HTMLWindowEvents2() 	{

		public void onunload( mol.mshtml.IHTMLEventObj pEvtObj) {
			
			// call derived class override, if any, for tear down
	    	unload();	    
	    	
	    	// kill app gently from another thread
	    	new Thread( new Runnable() { 
	    		public void run () {
	    			System.exit(0);
	    			} 
	    		}).start();
	    }			 
		
	};	
	
	/**
	 * attach an HTML DOM element event source to a user handler interface
	 * @param event   : String defining DOM Element id attribute value
	 * @param <O> src : reference to event handler interface implementation class 
	 *  
	 */
	/**
	 * @param <O>
	 * @param event
	 * @param src
	 */
	@SuppressWarnings("unchecked")
	protected <  O extends com4j.Com4jObject >	
	void  attach( String event, O src ) {

		// get a derived class' field named 'event'
		java.lang.reflect.Field field = null;
		try {
			field = this.getClass().getField(event);
		} catch (SecurityException e) {
			return;
		} catch (NoSuchFieldException e) {
			return;
		}
		if ( field == null )
			return;

		// get type and value of this field
		Class clazz = field.getType();
		Object obj  = null;
		try {
			obj = field.get(this);
		} catch (IllegalArgumentException e) {
			return;
		} catch (IllegalAccessException e) {
			return;
		}
							
		if ( obj != null ) {
			
			// hook the event src to that field and cache the cookie
			com4j.EventCookie cookie = src.advise( clazz, clazz.cast(obj) );
			//if ( cookie != null )
				//this.cookies.add(cookie);									
		}
	}
	
	/**
	 * Default DISPID(0) Event Handler for MSHTML style Dispatch Event handlers
	 *  
	 */
	
	public class Handler {

		private Object obj = null;
		private Method method = null;
		
		public Handler( Object o, Method m) {
			this.obj = o;
			this.method = m;
		}
		
		@DISPID(0)
		public boolean handler() {
			try {
				return (Boolean)(this.method.invoke( this.obj ));
			} catch (IllegalArgumentException e) {
				e.printStackTrace();
			} catch (IllegalAccessException e) {
				e.printStackTrace();
			} catch (InvocationTargetException e) {
				e.printStackTrace();
			}
			return true;
		}				
	}	
	
	/**
	 * connect a MSHTML style dispatch event handler (event)
	 * from a DOM element (id) to a object (obj) of class (type)
	 */
	
	public <T extends com4j.Com4jObject> boolean connect( String event, String id, Object obj, Class<T> type) {
		
		// get reference to DOM node
		IHTMLElement el = this.doc3.getElementById(id);
		if ( el == null ) {
			return false;
		}	
		
		// cast DOM node to concrete event source type
		T e = el.queryInterface(type);
		if (e == null ) {
			return false;
		}
		
		try {
			
			// get reference to event handler method
			Method handler = obj.getClass().getMethod( event, new Class[] {} );
			// get reference to event source object's attach-event method
			Method source  = e.getClass().getMethod( event, new Class[] { Object.class } );
						
			// invoke the attach-event method on object e and pass
			// variant encapsulation IDispatch of Event handler
			source.invoke( e, COM4J.variant( Handler.class, new Handler( obj, handler )) ); 
			
		} catch (IllegalAccessException ex) {
			return false;
		} catch (InvocationTargetException ex) {
			return false;			
		} catch (SecurityException ex) {
			return false;
		} catch (NoSuchMethodException ex) {
			return false;
		} catch (IllegalArgumentException ex) {
			return false;			
		}
		return true;
	}	



	// members - COM Interfaces prefetched for the CodeBehind extension
	protected IXmoe moe = null;
	protected IMoeFrame frame = null;	
	protected IHTMLDocument2 doc2 = null;
	protected IHTMLDocument3 doc3 = null;
	protected IHTMLWindow2 wnd = null;
		
}
