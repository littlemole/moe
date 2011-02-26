
package org.oha7.mol.moe;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;

import org.oha7.dispdriver.interfaces.IDispatch;
import org.oha7.mol.moe.IMoeUserForm;

public interface IMoeScript extends IUnknown {

    @Dispid(1)
    void Run( String f, String engine);

    @Dispid(2)
    void Eval( String scrpt, String scrptLanguage);

    @Dispid(3)
    void Debug( String scrpt, String scrptLanguage);

    @Dispid(4)
    IDispatch CreateObjectAdmin( String progid);

    @Dispid(5)
    void ShowHtmlForm( String src, int l, int t, int w, int h, int formStyle);

    @Dispid(6)
    IMoeUserForm ShowUserForm( String pathname);

    @Dispid(7)
    IMoeUserForm DebugUserForm( String pathname);

    @Dispid(8)
    void System( String f);


}
