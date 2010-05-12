package com4j.tlbimp.def;

import com4j.GUID;
import com4j.IID;
import com4j.VTID;

/**
 * @author Kohsuke Kawaguchi (kk@kohsuke.org)
 */
@IID("{EE076FF5-2E16-4a23-AE24-5DF610F6006E}")
public interface IInterfaceDecl extends ITypeDecl, IInterface {
    @VTID(7)
    GUID getGUID();

    @VTID(8)
    int countMethods();

    @VTID(9)
    IMethod getMethod(int idx);

    /**
     * count the number of the base interfaces
     */
    @VTID(10)
    int countBaseInterfaces();

    /**
     * gets the base interface
     */
    @VTID(11)
    ITypeDecl getBaseInterface(int index);
}
