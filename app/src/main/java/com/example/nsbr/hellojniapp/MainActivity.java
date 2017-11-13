package com.example.nsbr.hellojniapp;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
        System.loadLibrary("my-lib");
        System.loadLibrary("android");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // get simple string from native
        String msg = getMessageFromNative();
        msg += "\n" + stringFromJNI() + " / date: " + getDay(2020, 10, 21);
        msg += "\n" + getAllProcessPid()[1];

        // access class member in native code and return result to caller
        MeshData obj = new MeshData(3);
        msg += "\n\nResult getMemberFieldFromNative: " + getMemberFieldFromNative(obj);
        msg += "\nResult invokeMemberFuncFromNative: " + invokeMemberFuncFromNative(obj);

        // create object in native method and return it to caller
        MeshData obj2 = createObjectFromNative(18);
        msg += "\n\nResult createObjectFromNative: " + obj2.getFacetCount();


        // process object array in native code and return result to caller
        MeshData[] objArray = new MeshData[]{new MeshData(10), new MeshData(20)};

        int arrayRes = processObjectArrayFromNative(objArray);
        msg += "\n\nResult processObjectArrayFromNative: " + arrayRes;

        TextView textView = new TextView(this);
        textView.setText(msg);
        setContentView(textView);

    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    private native String stringFromJNI();

    private native String getMessageFromNative();

    private native float getMemberFieldFromNative(MeshData obj);

    private native int invokeMemberFuncFromNative(MeshData obj);

    private native MeshData createObjectFromNative(int param);

    private native int processObjectArrayFromNative(MeshData[] objArray);

    private native String[] getAllProcessPid();

    private native int getDay(int year, int month, int day);
}
