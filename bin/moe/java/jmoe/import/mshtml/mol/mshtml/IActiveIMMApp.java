package mol.mshtml  ;

import com4j.*;

@IID("{08C0E040-62D1-11D1-9326-0060B067B86E}")
public interface IActiveIMMApp extends Com4jObject {
    @VTID(3)
    int associateContext(
        int hWnd,
        int hIME);

            @VTID(6)
            int createContext();

            @VTID(7)
            void destroyContext(
                int hIME);

            @VTID(8)
            mol.mshtml.IEnumRegisterWordA enumRegisterWordA(
                java.nio.Buffer hKL,
                @MarshalAs(NativeType.CSTR) java.lang.String szReading,
                int dwStyle,
                @MarshalAs(NativeType.CSTR) java.lang.String szRegister,
                java.nio.Buffer pData);

            @VTID(9)
            mol.mshtml.IEnumRegisterWordW enumRegisterWordW(
                java.nio.Buffer hKL,
                @MarshalAs(NativeType.Unicode) java.lang.String szReading,
                int dwStyle,
                @MarshalAs(NativeType.Unicode) java.lang.String szRegister,
                java.nio.Buffer pData);

            @VTID(10)
            int escapeA(
                java.nio.Buffer hKL,
                int hIMC,
                int uEscape,
                java.nio.Buffer pData);

            @VTID(11)
            int escapeW(
                java.nio.Buffer hKL,
                int hIMC,
                int uEscape,
                java.nio.Buffer pData);

                    @VTID(14)
                    void getCandidateListCountA(
                        int hIMC,
                        Holder<Integer> pdwListSize,
                        Holder<Integer> pdwBufLen);

                    @VTID(15)
                    void getCandidateListCountW(
                        int hIMC,
                        Holder<Integer> pdwListSize,
                        Holder<Integer> pdwBufLen);

                    @VTID(19)
                    void getCompositionStringA(
                        int hIMC,
                        int dwIndex,
                        int dwBufLen,
                        Holder<Integer> plCopied,
                        java.nio.Buffer pBuf);

                    @VTID(20)
                    void getCompositionStringW(
                        int hIMC,
                        int dwIndex,
                        int dwBufLen,
                        Holder<Integer> plCopied,
                        java.nio.Buffer pBuf);

                    @VTID(22)
                    int getContext(
                        int hWnd);

                            @VTID(25)
                            void getConversionStatus(
                                int hIMC,
                                Holder<Integer> pfdwConversion,
                                Holder<Integer> pfdwSentence);

                            @VTID(26)
                            int getDefaultIMEWnd(
                                int hWnd);

                            @VTID(27)
                            void getDescriptionA(
                                java.nio.Buffer hKL,
                                int uBufLen,
                                @MarshalAs(NativeType.CSTR) java.lang.String szDescription,
                                Holder<Integer> puCopied);

                            @VTID(28)
                            void getDescriptionW(
                                java.nio.Buffer hKL,
                                int uBufLen,
                                @MarshalAs(NativeType.Unicode) java.lang.String szDescription,
                                Holder<Integer> puCopied);

                            @VTID(29)
                            void getGuideLineA(
                                int hIMC,
                                int dwIndex,
                                int dwBufLen,
                                @MarshalAs(NativeType.CSTR) java.lang.String pBuf,
                                Holder<Integer> pdwResult);

                            @VTID(30)
                            void getGuideLineW(
                                int hIMC,
                                int dwIndex,
                                int dwBufLen,
                                @MarshalAs(NativeType.Unicode) java.lang.String pBuf,
                                Holder<Integer> pdwResult);

                            @VTID(31)
                            void getIMEFileNameA(
                                java.nio.Buffer hKL,
                                int uBufLen,
                                @MarshalAs(NativeType.CSTR) java.lang.String szFileName,
                                Holder<Integer> puCopied);

                            @VTID(32)
                            void getIMEFileNameW(
                                java.nio.Buffer hKL,
                                int uBufLen,
                                @MarshalAs(NativeType.Unicode) java.lang.String szFileName,
                                Holder<Integer> puCopied);

                            @VTID(33)
                            void getOpenStatus(
                                int hIMC);

                            @VTID(34)
                            int getProperty(
                                java.nio.Buffer hKL,
                                int fdwIndex);

                                    @VTID(38)
                                    int getVirtualKey(
                                        int hWnd);

                                    @VTID(39)
                                    java.nio.Buffer installIMEA(
                                        @MarshalAs(NativeType.CSTR) java.lang.String szIMEFileName,
                                        @MarshalAs(NativeType.CSTR) java.lang.String szLayoutText);

                                    @VTID(40)
                                    java.nio.Buffer installIMEW(
                                        @MarshalAs(NativeType.Unicode) java.lang.String szIMEFileName,
                                        @MarshalAs(NativeType.Unicode) java.lang.String szLayoutText);

                                    @VTID(41)
                                    void isIME(
                                        java.nio.Buffer hKL);

                                    @VTID(42)
                                    void isUIMessageA(
                                        int hWndIME,
                                        int msg,
                                        int wParam,
                                        int lParam);

                                    @VTID(43)
                                    void isUIMessageW(
                                        int hWndIME,
                                        int msg,
                                        int wParam,
                                        int lParam);

                                    @VTID(44)
                                    void notifyIME(
                                        int hIMC,
                                        int dwAction,
                                        int dwIndex,
                                        int dwValue);

                                    @VTID(45)
                                    void registerWordA(
                                        java.nio.Buffer hKL,
                                        @MarshalAs(NativeType.CSTR) java.lang.String szReading,
                                        int dwStyle,
                                        @MarshalAs(NativeType.CSTR) java.lang.String szRegister);

                                    @VTID(46)
                                    void registerWordW(
                                        java.nio.Buffer hKL,
                                        @MarshalAs(NativeType.Unicode) java.lang.String szReading,
                                        int dwStyle,
                                        @MarshalAs(NativeType.Unicode) java.lang.String szRegister);

                                    @VTID(47)
                                    void releaseContext(
                                        int hWnd,
                                        int hIMC);

                                                @VTID(51)
                                                void setCompositionStringA(
                                                    int hIMC,
                                                    int dwIndex,
                                                    java.nio.Buffer pComp,
                                                    int dwCompLen,
                                                    java.nio.Buffer pRead,
                                                    int dwReadLen);

                                                @VTID(52)
                                                void setCompositionStringW(
                                                    int hIMC,
                                                    int dwIndex,
                                                    java.nio.Buffer pComp,
                                                    int dwCompLen,
                                                    java.nio.Buffer pRead,
                                                    int dwReadLen);

                                                    @VTID(54)
                                                    void setConversionStatus(
                                                        int hIMC,
                                                        int fdwConversion,
                                                        int fdwSentence);

                                                    @VTID(55)
                                                    void setOpenStatus(
                                                        int hIMC,
                                                        int fOpen);

                                                        @VTID(57)
                                                        void simulateHotKey(
                                                            int hWnd,
                                                            int dwHotKeyID);

                                                        @VTID(58)
                                                        void unregisterWordA(
                                                            java.nio.Buffer hKL,
                                                            @MarshalAs(NativeType.CSTR) java.lang.String szReading,
                                                            int dwStyle,
                                                            @MarshalAs(NativeType.CSTR) java.lang.String szUnregister);

                                                        @VTID(59)
                                                        void unregisterWordW(
                                                            java.nio.Buffer hKL,
                                                            @MarshalAs(NativeType.Unicode) java.lang.String szReading,
                                                            int dwStyle,
                                                            @MarshalAs(NativeType.Unicode) java.lang.String szUnregister);

                                                        @VTID(60)
                                                        void activate(
                                                            int fRestoreLayout);

                                                        @VTID(61)
                                                        void deactivate();

                                                        @VTID(62)
                                                        int onDefWindowProc(
                                                            int hWnd,
                                                            int msg,
                                                            int wParam,
                                                            int lParam);

                                                        @VTID(63)
                                                        void filterClientWindows(
                                                            Holder<Short> aaClassList,
                                                            int uSize);

                                                        @VTID(64)
                                                        int getCodePageA(
                                                            java.nio.Buffer hKL);

                                                        @VTID(65)
                                                        short getLangId(
                                                            java.nio.Buffer hKL);

                                                        @VTID(66)
                                                        void associateContextEx(
                                                            int hWnd,
                                                            int hIMC,
                                                            int dwFlags);

                                                        @VTID(67)
                                                        void disableIME(
                                                            int idThread);

                                                                @VTID(70)
                                                                mol.mshtml.IEnumInputContext enumInputContext(
                                                                    int idThread);

                                                            }
