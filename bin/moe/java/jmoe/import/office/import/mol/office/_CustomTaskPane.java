package mol.office  ;

import com4j.*;

@IID("{000C033B-0000-0000-C000-000000000046}")
public interface _CustomTaskPane extends Com4jObject {
    @VTID(7)
    @DefaultMethod
    java.lang.String title();

    @VTID(8)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject application();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject window();

    @VTID(10)
    boolean visible();

    @VTID(11)
    void visible(
        boolean prop);

    @VTID(12)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject contentControl();

    @VTID(13)
    int height();

    @VTID(14)
    void height(
        int prop);

    @VTID(15)
    int width();

    @VTID(16)
    void width(
        int prop);

    @VTID(17)
    mol.office.MsoCTPDockPosition dockPosition();

    @VTID(18)
    void dockPosition(
        mol.office.MsoCTPDockPosition prop);

    @VTID(19)
    mol.office.MsoCTPDockPositionRestrict dockPositionRestrict();

    @VTID(20)
    void dockPositionRestrict(
        mol.office.MsoCTPDockPositionRestrict prop);

    @VTID(21)
    void delete();

}
