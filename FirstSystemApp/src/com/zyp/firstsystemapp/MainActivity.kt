package com.zyp.firstsystemapp

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.airbnb.lottie.Lottie
import com.airbnb.lottie.LottieConfig
import com.zyp.firstsystemandroidlibrary.MyCustomView

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        val myView = MyCustomView(this)
        Lottie.initialize(LottieConfig.Builder().build())
    }
}