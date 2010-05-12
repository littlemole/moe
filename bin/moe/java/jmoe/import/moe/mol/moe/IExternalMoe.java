package mol.moe  ;

import com4j.*;

/**
 * IExternalMoxy Xmoe Interface - external interface visible for scripts from within embedded IE
 */
@IID("{5AA6374E-4995-4F49-AF45-6A047654CDD2}")
public interface IExternalMoe extends Com4jObject {
    /**
     * Get moe application object reference
     */
    @VTID(7)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject moe();

    /**
     * Get reference to current frame interface
     */
    @VTID(8)
    mol.moe.IMoeFrame frame();

    /**
     * Get Code Behind - for .NET CodeBehind Scripts
     */
    @VTID(9)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject code();

    /**
     * Close current frame
     */
    @VTID(10)
    void close();

    /**
     * CreateObject - creates new COM object
     */
    @VTID(11)
    @ReturnValue(type=NativeType.Dispatch)
    com4j.Com4jObject createObject(
        java.lang.String progid);

    /**
     * Put Code Behind - for .NET CodeBehind Scripts
     */
    @VTID(12)
    void codeBehind(
        java.lang.String fname);

}
