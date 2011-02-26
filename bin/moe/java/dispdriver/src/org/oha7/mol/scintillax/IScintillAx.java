
package org.oha7.mol.scintillax;

import org.oha7.dispdriver.annotations.ProgId;
import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;

import org.oha7.mol.scintillax.IScintillAxProperties;
import org.oha7.mol.scintillax.IScintillAxText;
import org.oha7.mol.scintillax.IScintillAxPosition;
import org.oha7.mol.scintillax.IScintillAxSelection;
import org.oha7.mol.scintillax.IScintillAxLine;
import org.oha7.mol.scintillax.IScintillAxAnnotation;
import org.oha7.mol.scintillax.IScintillAxMarkers;

@ProgId("Scintilla.ScintillAx")
public interface IScintillAx extends IUnknown {

    @Dispid(1)
	IScintillAxProperties getProperties();

    @Dispid(2)
	IScintillAxText getText();

    @Dispid(3)
	IScintillAxPosition getPosition();

    @Dispid(4)
	IScintillAxSelection getSelection();

    @Dispid(5)
	IScintillAxLine getline();

    @Dispid(6)
	IScintillAxAnnotation getAnnotation();

    @Dispid(7)
	IScintillAxMarkers getmarkers();

    @Dispid(8)
    void Load( String fname);

    @Dispid(9)
    void LoadUTF8( String fname);

    @Dispid(10)
    void Save( );

    @Dispid(11)
    void SaveAs( String fname);

    @Dispid(12)
    void Undo( );

    @Dispid(13)
    void Redo( );

    @Dispid(14)
    void SavePoint( );

    @Dispid(15)
    void SetFocus( );

    @Dispid(16)
    void ZoomIn( );

    @Dispid(17)
    void ZoomOut( );

    @Dispid(18)
    void Print( );

    @Dispid(19)
    void ShowProperties( );

    @Dispid(20)
    void InsertColorDialog( );


}
