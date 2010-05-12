
import mol.DOMEvent;
import mol.HtmlEvent;
import mol.CodeBehind;
import mol.mshtml.IHTMLElement;
import mol.mshtml.IHTMLEventObj;
import mol.mshtml.events.HTMLElementEvents2;
import mol.mshtml.events.HTMLInputTextElementEvents2;

import com4j.COM4J;
import com4j.DISPID;
   
public class CodeBehindTest extends CodeBehind {  
	   
	
	public void load() {
		
		IHTMLElement el = this.doc3.getElementById("test");
		if ( el != null ) {
			el.innerHTML("hohoh1 xmas!");
		}		
		
		this.frame.codeBehind(COM4J.dispatch(CodeBehindTest.class, this));

		/*
		com4j.Com4jObject wrapper = COM4J.dispatch(CodeBehindTest.class, this);
		if ( wrapper != null )
		{
			this.frame.codeBehind(wrapper);
		
			if ( el != null ) {
				//el.innerHTML("hohoh3 xmas!");
			}		
		}
		*/
	}
 
	public void unload() {

	}
	
	@DISPID(1)
	public void helo() {
		IHTMLElement e = doc3.getElementById("test");
		if ( e.innerHTML().equals("helo xmas!"))
			e.innerHTML("elo xmas!");
		else
			e.innerHTML("helo xmas!");	 	
	}	
	
	@DISPID(2)
	public void helo2() {
		IHTMLElement e = doc3.getElementById("test");
		if ( e.innerHTML().equals("helo2 xmas!"))
			e.innerHTML("elo2 xmas!");
		else
			e.innerHTML("helo2 xmas!");	
	}
	
	@DOMEvent("tmp")
	public boolean onclick() {
		IHTMLElement e = doc3.getElementById("tmp");
		if ( e.innerHTML().equals("jojojo xmas!"))
			e.innerHTML("jejeje xmas!");
		else
			e.innerHTML("jojojo xmas!");		
		return true;
	}	
	
	@DOMEvent("tmp")
	public boolean onmouseover() {
		IHTMLElement e = doc3.getElementById("tmp");
		if ( e.innerHTML().equals("jajaja xmas!"))
			e.innerHTML("jijiji xmas!");
		else
			e.innerHTML("jajaja xmas!");		
		return true;
	}		
	
 
	@HtmlEvent("test")
	public HTMLElementEvents2 myEvent = new HTMLElementEvents2() 	{

		public boolean onclick( IHTMLEventObj pEvtObj) {
			
			IHTMLElement el = pEvtObj.srcElement();
			if ( el != null ) {
				if ( el.innerHTML().equals("hohoho xmas!"))
					el.innerHTML("hahaha xmas!");
				else
					el.innerHTML("hohoho xmas!");
			}			
	    	return true;
	    }			 
		
	};
	
	@HtmlEvent("input")
	public HTMLInputTextElementEvents2 myEvent2 = new HTMLInputTextElementEvents2() 	{

		public boolean onclick( IHTMLEventObj pEvtObj) {
				
			IHTMLElement e = doc3.getElementById("test");
			if ( e.innerHTML().equals("hehehe xmas!"))
				e.innerHTML("hihihi xmas!");
			else
				e.innerHTML("hehehe xmas!");
	    	return true;
	    }			 
		
	};
	

}
