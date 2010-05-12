package mol.word  ;

import com4j.*;

@IID("{0002091F-0000-0000-C000-000000000046}")
public interface MailMergeFields extends Com4jObject,Iterable<Com4jObject> {
    @VTID(7)
    mol.word._Application application();

    @VTID(8)
    int creator();

    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject parent();

    @VTID(10)
    java.util.Iterator<Com4jObject> iterator();

    @VTID(11)
    int count();

    @VTID(12)
    @DefaultMethod
    mol.word.MailMergeField item(
        int index);

    @VTID(13)
    mol.word.MailMergeField add(
        mol.word.Range range,
        java.lang.String name);

    @VTID(14)
    mol.word.MailMergeField addAsk(
        mol.word.Range range,
        java.lang.String name,
        java.lang.Object prompt,
        java.lang.Object defaultAskText,
        java.lang.Object askOnce);

    @VTID(15)
    mol.word.MailMergeField addFillIn(
        mol.word.Range range,
        java.lang.Object prompt,
        java.lang.Object defaultFillInText,
        java.lang.Object askOnce);

    @VTID(16)
    mol.word.MailMergeField addIf(
        mol.word.Range range,
        java.lang.String mergeField,
        mol.word.WdMailMergeComparison comparison,
        java.lang.Object compareTo,
        java.lang.Object trueAutoText,
        java.lang.Object trueText,
        java.lang.Object falseAutoText,
        java.lang.Object falseText);

    @VTID(17)
    mol.word.MailMergeField addMergeRec(
        mol.word.Range range);

    @VTID(18)
    mol.word.MailMergeField addMergeSeq(
        mol.word.Range range);

    @VTID(19)
    mol.word.MailMergeField addNext(
        mol.word.Range range);

    @VTID(20)
    mol.word.MailMergeField addNextIf(
        mol.word.Range range,
        java.lang.String mergeField,
        mol.word.WdMailMergeComparison comparison,
        java.lang.Object compareTo);

    @VTID(21)
    mol.word.MailMergeField addSet(
        mol.word.Range range,
        java.lang.String name,
        java.lang.Object valueText,
        java.lang.Object valueAutoText);

    @VTID(22)
    mol.word.MailMergeField addSkipIf(
        mol.word.Range range,
        java.lang.String mergeField,
        mol.word.WdMailMergeComparison comparison,
        java.lang.Object compareTo);

}
