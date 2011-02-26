
package org.oha7.mol.moe;

import org.oha7.dispdriver.annotations.Dispid;
import org.oha7.dispdriver.interfaces.IUnknown;

import org.oha7.dispdriver.interfaces.IDispatch;

public interface IWebBrowserEvents extends IUnknown {

    @Dispid(102)
    void StatusTextChange( String Text);

    @Dispid(108)
    void ProgressChange( int Progress, int ProgressMax);

    @Dispid(105)
    void CommandStateChange( int Command, boolean Enable);

    @Dispid(106)
    void DownloadBegin( );

    @Dispid(104)
    void DownloadComplete( );

    @Dispid(113)
    void TitleChange( String Text);

    @Dispid(112)
    void PropertyChange( String szProperty);

    @Dispid(250)
    void BeforeNavigate2( IDispatch pDisp, Object URL, Object Flags, Object TargetFrameName, Object PostData, Object Headers, boolean Cancel);

    @Dispid(251)
    void NewWindow2( IDispatch ppDisp, boolean Cancel);

    @Dispid(252)
    void NavigateComplete2( IDispatch pDisp, Object URL);

    @Dispid(259)
    void DocumentComplete( IDispatch pDisp, Object URL);

    @Dispid(253)
    void OnQuit( );

    @Dispid(254)
    void OnVisible( boolean Visible);

    @Dispid(255)
    void OnToolBar( boolean ToolBar);

    @Dispid(256)
    void OnMenuBar( boolean MenuBar);

    @Dispid(257)
    void OnStatusBar( boolean StatusBar);

    @Dispid(258)
    void OnFullScreen( boolean FullScreen);

    @Dispid(260)
    void OnTheaterMode( boolean TheaterMode);

    @Dispid(262)
    void WindowSetResizable( boolean Resizable);

    @Dispid(264)
    void WindowSetLeft( int Left);

    @Dispid(265)
    void WindowSetTop( int Top);

    @Dispid(266)
    void WindowSetWidth( int Width);

    @Dispid(267)
    void WindowSetHeight( int Height);

    @Dispid(263)
    void WindowClosing( boolean IsChildWindow, boolean Cancel);

    @Dispid(268)
    void ClientToHostWindow( int CX, int CY);

    @Dispid(269)
    void SetSecureLockIcon( int SecureLockIcon);

    @Dispid(270)
    void FileDownload( boolean Cancel);

    @Dispid(271)
    void NavigateError( IDispatch pDisp, Object URL, Object Frame, Object StatusCode, boolean Cancel);

    @Dispid(225)
    void PrintTemplateInstantiation( IDispatch pDisp);

    @Dispid(226)
    void PrintTemplateTeardown( IDispatch pDisp);

    @Dispid(227)
    void UpdatePageStatus( IDispatch pDisp, Object nPage, Object fDone);

    @Dispid(272)
    void PrivacyImpactedStateChange( boolean bImpacted);


}
