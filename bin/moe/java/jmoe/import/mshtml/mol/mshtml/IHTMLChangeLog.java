package mol.mshtml  ;

import com4j.*;

@IID("{3050F649-98B5-11CF-BB82-00AA00BDCE0B}")
public interface IHTMLChangeLog extends Com4jObject {
    @VTID(3)
    int getNextChange(
        Holder<Byte> pbBuffer,
        int nBufferSize);

}
