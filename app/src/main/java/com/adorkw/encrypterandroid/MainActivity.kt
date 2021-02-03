package com.adorkw.encrypterandroid

import android.content.ClipData
import android.content.ClipboardManager
import android.content.Context
import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.view.View
import android.widget.Button
import android.widget.EditText
import android.widget.TextView
import android.widget.Toast

class MainActivity : AppCompatActivity() {

    lateinit var inputET: EditText
    lateinit var keyET: EditText
    lateinit var outputET: EditText
    lateinit var copyBT: Button
    lateinit var encrypt: Button
    lateinit var decrypt: Button
    lateinit var encrypter: Encrypter

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        inputET = findViewById(R.id.editTextInput)
        keyET = findViewById(R.id.editTextKey)
        outputET = findViewById(R.id.editTextOutput)
        copyBT = findViewById(R.id.buttonCopy)
        encrypt = findViewById(R.id.buttonEncrypt)
        decrypt = findViewById(R.id.buttonDecrypt)

        encrypter = Encrypter()

        copyBT.setOnClickListener(object : View.OnClickListener {
            override fun onClick(view: View?) {
                val clipboardManager: ClipboardManager =
                    getSystemService(Context.CLIPBOARD_SERVICE) as ClipboardManager;
                val clipData = ClipData.newPlainText("Secret text", outputET.text.toString())
                clipboardManager.setPrimaryClip(clipData)

                Toast.makeText(applicationContext, "Copied", Toast.LENGTH_SHORT).show()
            }

        })
        encrypt.setOnClickListener(object : View.OnClickListener {
            override fun onClick(view: View?) {
                outputET.setText(encrypter.encrypt(inputET.text.toString(), keyET.text.toString()))
            }
        })
        decrypt.setOnClickListener(object : View.OnClickListener {
            override fun onClick(view: View?) {
                outputET.setText(encrypter.decrypt(inputET.text.toString(), keyET.text.toString()))
            }
        })
    }

}