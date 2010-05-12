package mol.wsh  ;

import com4j.*;

@IID("{C7C3F5A3-88A3-11D0-ABCB-00A0C90FFFC0}")
public interface IFolderCollection extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.wsh.IFolder add(
        java.lang.String name);

    @VTID(8)
    @DefaultMethod
    mol.wsh.IFolder item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object key);

    @VTID(9)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(10)
    int count();

}
