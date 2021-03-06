package org.oha7.test;

import java.lang.reflect.InvocationTargetException;

import org.oha7.dispdriver.Factory;
import org.oha7.dispdriver.interfaces.IDispatch;
import org.oha7.mol.moe.IMoe;
import org.oha7.mol.moe.IMoeDialogs;
import org.oha7.mol.moe.IMoeDocument;
import org.oha7.mol.moe.IMoeDocumentCollection;
import org.oha7.mol.scintillax.IScintillAx;
import org.oha7.mol.scintillax.IScintillAxText;

public class Client {
	
	public static String test( IDispatch disp ) throws SecurityException, IllegalArgumentException, NoSuchMethodException, InstantiationException, IllegalAccessException, InvocationTargetException {

		disp.invoke("hello");
		return "thx";
	}
	
	public static void test2( IMoe moe ) {
		
		IMoeDocumentCollection docs = moe.getDocuments();
		IMoeDocument doc = docs.New();
		
		IDispatch disp = doc.getObject();
		IScintillAx sci = disp.QueryInterface(IScintillAx.class);
		
		IScintillAxText text = sci.getText();
		text.SetText("generated from java!");
		
		text.Release();
		disp.Release();
		sci.Release();
		docs.Release();
	}
	
	public static void main() throws SecurityException, IllegalArgumentException, NoSuchMethodException, InstantiationException, IllegalAccessException, InvocationTargetException {
				
	
		IMoe moe = Factory.getObject(IMoe.class);
		
		IMoeDialogs dialogs = moe.getDialogs();
		dialogs.Help();
		
		@SuppressWarnings("unused")
		int i = dialogs.MsgBox( "hu", "ha",0);
		
		dialogs.Release();
		moe.Release();
	}
}
