
package org.oha7.mol.moe;

import org.oha7.dispdriver.annotations.ProgId;
import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;

import org.oha7.mol.moe.IMoeDocumentCollection;
import org.oha7.mol.moe.IMoeView;
import org.oha7.mol.moe.IMoeDocument;
import org.oha7.mol.moe.IMoeConfig;
import org.oha7.mol.moe.IMoeScript;
import org.oha7.mol.moe.IMoeDialogs;

@ProgId("Moe.Application")
public interface IMoe extends IUnknown {

    @Dispid(1)
	IMoeDocumentCollection getDocuments();

    @Dispid(2)
	IMoeView getView();

    @Dispid(3)
	IMoeDocument getActiveDoc();

    @Dispid(4)
	IMoeConfig getConfig();

    @Dispid(5)
	IMoeScript getScript();

    @Dispid(6)
	IMoeDialogs getDialogs();

    @Dispid(7)
    void Exit( );


}
