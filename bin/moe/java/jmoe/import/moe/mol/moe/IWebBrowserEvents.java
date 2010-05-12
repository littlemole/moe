package mol.moe  ;

import com4j.*;

/**
 * Event interface for DWebBrowserEvents2 dual
 */
@IID("{F010AA89-5CF5-4BCE-BABE-5ADAE3D300EB}")
public interface IWebBrowserEvents extends Com4jObject {
    /**
     * Statusbar text changed.
     */
    @VTID(7)
    void statusTextChange(
        java.lang.String text);

    /**
     * Fired when download progress is updated.
     */
    @VTID(8)
    void progressChange(
        int progress,
        int progressMax);

    /**
     * The enabled state of a command changed.
     */
    @VTID(9)
    void commandStateChange(
        int command,
        boolean enable);

    /**
     * Download of a page started.
     */
    @VTID(10)
    void downloadBegin();

    /**
     * Download of page complete.
     */
    @VTID(11)
    void downloadComplete();

    /**
     * Document title changed.
     */
    @VTID(12)
    void titleChange(
        java.lang.String text);

    /**
     * Fired when the PutProperty method has been called.
     */
    @VTID(13)
    void propertyChange(
        java.lang.String szProperty);

    /**
     * Fired before navigate occurs in the given WebBrowser (window or frameset element). The processing of this navigation may be modified.
     */
    @VTID(14)
    void beforeNavigate2(
        @MarshalAs(NativeType.Dispatch) com4j.Com4jObject pDisp,
        java.lang.Object url,
        java.lang.Object flags,
        java.lang.Object targetFrameName,
        java.lang.Object postData,
        java.lang.Object headers,
        Holder<Boolean> cancel);

        /**
         * Fired when the document being navigated to becomes visible and enters the navigation stack.
         */
        @VTID(16)
        void navigateComplete2(
            @MarshalAs(NativeType.Dispatch) com4j.Com4jObject pDisp,
            java.lang.Object url);

        /**
         * Fired when the document being navigated to reaches ReadyState_Complete.
         */
        @VTID(17)
        void documentComplete(
            @MarshalAs(NativeType.Dispatch) com4j.Com4jObject pDisp,
            java.lang.Object url);

        /**
         * Fired when application is quiting.
         */
        @VTID(18)
        void onQuit();

        /**
         * Fired when the window should be shown/hidden
         */
        @VTID(19)
        void onVisible(
            boolean visible);

        /**
         * Fired when the toolbar  should be shown/hidden
         */
        @VTID(20)
        void onToolBar(
            boolean toolBar);

        /**
         * Fired when the menubar should be shown/hidden
         */
        @VTID(21)
        void onMenuBar(
            boolean menuBar);

        /**
         * Fired when the statusbar should be shown/hidden
         */
        @VTID(22)
        void onStatusBar(
            boolean statusBar);

        /**
         * Fired when fullscreen mode should be on/off
         */
        @VTID(23)
        void onFullScreen(
            boolean fullScreen);

        /**
         * Fired when theater mode should be on/off
         */
        @VTID(24)
        void onTheaterMode(
            boolean theaterMode);

        /**
         * Fired when the host window should allow/disallow resizing
         */
        @VTID(25)
        void windowSetResizable(
            boolean resizable);

        /**
         * Fired when the host window should change its Left coordinate
         */
        @VTID(26)
        void windowSetLeft(
            int left);

        /**
         * Fired when the host window should change its Top coordinate
         */
        @VTID(27)
        void windowSetTop(
            int top);

        /**
         * Fired when the host window should change its width
         */
        @VTID(28)
        void windowSetWidth(
            int width);

        /**
         * Fired when the host window should change its height
         */
        @VTID(29)
        void windowSetHeight(
            int height);

        /**
         * Fired when the WebBrowser is about to be closed by script
         */
        @VTID(30)
        void windowClosing(
            boolean isChildWindow,
            Holder<Boolean> cancel);

        /**
         * Fired to request client sizes be converted to host window sizes
         */
        @VTID(31)
        void clientToHostWindow(
            Holder<Integer> cx,
            Holder<Integer> cy);

        /**
         * Fired to indicate the security level of the current web page contents
         */
        @VTID(32)
        void setSecureLockIcon(
            int secureLockIcon);

        /**
         * Fired to indicate the File Download dialog is opening
         */
        @VTID(33)
        void fileDownload(
            Holder<Boolean> cancel);

        /**
         * Fired when a binding error occurs (window or frameset element).
         */
        @VTID(34)
        void navigateError(
            @MarshalAs(NativeType.Dispatch) com4j.Com4jObject pDisp,
            java.lang.Object url,
            java.lang.Object frame,
            java.lang.Object statusCode,
            Holder<Boolean> cancel);

        /**
         * Fired when a print template is instantiated.
         */
        @VTID(35)
        void printTemplateInstantiation(
            @MarshalAs(NativeType.Dispatch) com4j.Com4jObject pDisp);

        /**
         * Fired when a print template destroyed.
         */
        @VTID(36)
        void printTemplateTeardown(
            @MarshalAs(NativeType.Dispatch) com4j.Com4jObject pDisp);

        /**
         * Fired when a page is spooled. When it is fired can be changed by a custom template.
         */
        @VTID(37)
        void updatePageStatus(
            @MarshalAs(NativeType.Dispatch) com4j.Com4jObject pDisp,
            java.lang.Object nPage,
            java.lang.Object fDone);

        /**
         * Fired when the global privacy impacted state changes
         */
        @VTID(38)
        void privacyImpactedStateChange(
            boolean bImpacted);

    }
