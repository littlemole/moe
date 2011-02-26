
package org.oha7.mol.pipedprocess;

import org.oha7.dispdriver.annotations.ProgId;
import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;

import org.oha7.dispdriver.interfaces.IDispatch;

@ProgId("PipedProcess.PipedProcessControl")
public interface IPipedProcess extends IUnknown {

    @Dispid(1)
	boolean getAsync();

    @Dispid(2)
	int getreadyState();

    @Dispid(3)
	boolean getEof();

    @Dispid(4)
	boolean getErrEof();

    @Dispid(1)
	void setAsync(boolean vb);

    @Dispid(12)
	void setonComplete(IDispatch param0);

    @Dispid(5)
    boolean Create( String cmdline);

    @Dispid(6)
    boolean Write( String s);

    @Dispid(7)
    void CloseOut( );

    @Dispid(8)
    String ReadLine( );

    @Dispid(9)
    String ReadErrLine( );

    @Dispid(10)
    void Close( );

    @Dispid(11)
    void Terminate( );


}
