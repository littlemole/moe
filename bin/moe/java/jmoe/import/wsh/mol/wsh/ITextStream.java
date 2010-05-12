package mol.wsh  ;

import com4j.*;

@IID("{53BAD8C1-E718-11CF-893D-00A0C9054228}")
public interface ITextStream extends Com4jObject {
    @VTID(7)
    int line();

    @VTID(8)
    int column();

    @VTID(9)
    boolean atEndOfStream();

    @VTID(10)
    boolean atEndOfLine();

    @VTID(11)
    java.lang.String read(
        int characters);

    @VTID(12)
    java.lang.String readLine();

    @VTID(13)
    java.lang.String readAll();

    @VTID(14)
    void write(
        java.lang.String text);

    @VTID(15)
    void writeLine(
        java.lang.String text);

    @VTID(16)
    void writeBlankLines(
        int lines);

    @VTID(17)
    void skip(
        int characters);

    @VTID(18)
    void skipLine();

    @VTID(19)
    void close();

}
