package mol.vba  ;

import com4j.*;

@IID("{DA936B62-AC8B-11D1-B6E5-00A0C90F2744}")
public interface _AddIns extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    @DefaultMethod
    mol.vba.AddIn item(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(8)
    mol.vba.VBE vbe();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    void update();

}
