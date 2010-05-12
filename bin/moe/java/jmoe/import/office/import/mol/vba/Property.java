package mol.vba  ;

import com4j.*;

@IID("{0002E18C-0000-0000-C000-000000000046}")
public interface Property extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object value();

    @VTID(8)
    @DefaultMethod
    void value(
        @MarshalAs(NativeType.VARIANT) java.lang.Object lppvReturn);

    @VTID(9)
    @ReturnValue(type=NativeType.VARIANT)
    java.lang.Object indexedValue(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index4);

    @VTID(10)
    void indexedValue(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index1,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index2,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index3,
        @MarshalAs(NativeType.VARIANT) java.lang.Object index4,
        @MarshalAs(NativeType.VARIANT) java.lang.Object lppvReturn);

    @VTID(11)
    short numIndices();

    @VTID(12)
    mol.vba.Application application();

    @VTID(13)
    mol.vba._Properties parent();

    @VTID(14)
    java.lang.String name();

    @VTID(15)
    mol.vba.VBE vbe();

    @VTID(16)
    mol.vba._Properties collection();

    @VTID(17)
    com4j.Com4jObject object();

    @VTID(18)
    void object(
        com4j.Com4jObject lppunk);

}
