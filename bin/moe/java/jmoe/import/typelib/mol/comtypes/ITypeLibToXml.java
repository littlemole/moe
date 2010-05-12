package mol.comtypes  ;

import com4j.*;

/**
 * ITypeLibToXml - converts COM Typelibraries to XML
 */
@IID("{2D9ABF3A-0013-4761-9F9F-9AFA71AF123C}")
public interface ITypeLibToXml extends Com4jObject {
    /**
     * load a Type library from file
     */
    @VTID(7)
    boolean load(
        java.lang.String filename);

    /**
     * Get XML representation for loaded typelib
     */
    @VTID(8)
    java.lang.String xml();

    /**
     * transform a loaded type library via XSLT
     */
    @VTID(9)
    java.lang.String transform(
        @MarshalAs(NativeType.VARIANT) java.lang.Object xsltDoc);

    /**
     * asynchronous transformation - specify type library file, optional filter and XSL Document
     */
    @VTID(10)
    void asyncDocumentation(
        java.lang.String filename,
        java.lang.String filter,
        @MarshalAs(NativeType.VARIANT) java.lang.Object xsltDoc);

    /**
     * on Complete script handler
     */
    @VTID(11)
    void onComplete(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject onCompleteHandler);

    /**
     * on Complete script handler
     */
    @VTID(12)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject onComplete();

    /**
     * on Status script handler
     */
    @VTID(13)
    void onStatus(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject onStatusHandler);

    /**
     * on Status script handler
     */
    @VTID(14)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject onStatus();

    /**
     * on Complete script handler
     */
    @VTID(15)
    boolean error();

    /**
     * Get Result Doc as String
     */
    @VTID(16)
    java.lang.String result();

}
