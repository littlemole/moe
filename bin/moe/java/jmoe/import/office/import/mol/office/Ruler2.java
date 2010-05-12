package mol.office  ;

import com4j.*;

@IID("{000C03C1-0000-0000-C000-000000000046}")
public interface Ruler2 extends mol.office._IMsoDispObj {
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    mol.office.RulerLevels2 levels();

    @VTID(10)
    @ReturnValue(defaultPropertyThrough={mol.office.RulerLevels2.class})
    mol.office.RulerLevel2 levels(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

    @VTID(11)
    mol.office.TabStops2 tabStops();

    @VTID(11)
    @ReturnValue(defaultPropertyThrough={mol.office.TabStops2.class})
    mol.office.TabStop2 tabStops(
        @MarshalAs(NativeType.VARIANT) java.lang.Object index);

}
