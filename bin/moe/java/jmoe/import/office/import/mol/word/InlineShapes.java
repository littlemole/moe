package mol.word  ;

import com4j.*;

@IID("{000209A9-0000-0000-C000-000000000046}")
public interface InlineShapes extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    int count();

    @VTID(11)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(12)
    @DefaultMethod
    mol.word.InlineShape item(
        int index);

    @VTID(13)
    mol.word.InlineShape addPicture(
        java.lang.String fileName,
        java.lang.Object linkToFile,
        java.lang.Object saveWithDocument,
        java.lang.Object range);

    @VTID(14)
    mol.word.InlineShape addOLEObject(
        java.lang.Object classType,
        java.lang.Object fileName,
        java.lang.Object linkToFile,
        java.lang.Object displayAsIcon,
        java.lang.Object iconFileName,
        java.lang.Object iconIndex,
        java.lang.Object iconLabel,
        java.lang.Object range);

    @VTID(15)
    mol.word.InlineShape addOLEControl(
        java.lang.Object classType,
        java.lang.Object range);

    @VTID(16)
    mol.word.InlineShape _new(
        mol.word.Range range);

    @VTID(17)
    mol.word.InlineShape addHorizontalLine(
        java.lang.String fileName,
        java.lang.Object range);

    @VTID(18)
    mol.word.InlineShape addHorizontalLineStandard(
        java.lang.Object range);

    @VTID(19)
    mol.word.InlineShape addPictureBullet(
        java.lang.String fileName,
        java.lang.Object range);

    @VTID(20)
    mol.word.InlineShape addChart(
        mol.excel.XlChartType type,
        java.lang.Object range);

}
