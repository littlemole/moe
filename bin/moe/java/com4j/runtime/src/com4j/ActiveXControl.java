package com4j;

import java.awt.Canvas;
import java.awt.Graphics;

/**
 * {@link Canvas} that hosts an OLE control (AKA ActiveX control.)
 *
 * @author Kohsuke Kawaguchi
 */
public class ActiveXControl extends Canvas {
    private boolean autoDispose = false;
    private int nativePeer;

    public void removeNotify() {
        if(autoDispose) {
            dispose();
        }
        super.removeNotify();
    }

    public void paint(Graphics g) {
        if(nativePeer==0) {
            new Task<Void>() {
                public Void call() {
                    nativePeer = initWindow();
                    return null;
                }
            }.execute();
        }
        super.paint(g);
    }

    private void dispose() {
        if(nativePeer!=0) {
            new Task<Void>() {
                public Void call() {
                    dispose0(nativePeer);
                    nativePeer = 0;
                    return null;
                }
            }.execute();
        }
    }

    /**
     * Disposes the native window.
     */
    private native void dispose0(int nativePeer);

    /**
     * Creates the native window.
     */
    private native int initWindow();
}
