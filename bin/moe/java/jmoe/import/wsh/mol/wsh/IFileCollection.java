package mol.wsh  ;

import com4j.*;

@IID("{C7C3F5A5-88A3-11D0-ABCB-00A0C90FFFC0}")
public interface IFileCollection extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    @DefaultMethod
    mol.wsh.IFile item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object key);

    @VTID(8)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(9)
    int count();

}
