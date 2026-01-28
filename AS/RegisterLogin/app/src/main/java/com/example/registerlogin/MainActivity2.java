package com.example.registerlogin;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity2 extends AppCompatActivity {

    EditText etLoginUsername, etLoginPassword;
    Button btnLogin;
    DBHelper db;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        etLoginUsername = findViewById(R.id.etLoginUsername);
        etLoginPassword = findViewById(R.id.etLoginPassword);
        btnLogin = findViewById(R.id.btnLogin);

        db = new DBHelper(this);

        btnLogin.setOnClickListener(v -> {
            boolean valid = db.checkLogin(
                    etLoginUsername.getText().toString(),
                    etLoginPassword.getText().toString()
            );

            if (valid) {
                Toast.makeText(this,
                        "Login successful",
                        Toast.LENGTH_SHORT).show();
            } else {
                Toast.makeText(this,
                        "Invalid username or password",
                        Toast.LENGTH_SHORT).show();
            }
        });
    }
}