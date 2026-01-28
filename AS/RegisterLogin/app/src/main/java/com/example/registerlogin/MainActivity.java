package com.example.registerlogin;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    EditText etUsername, etPassword;
    Button btnRegister, btnGoLogin;
    DBHelper db;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        etUsername = findViewById(R.id.etUsername);
        etPassword = findViewById(R.id.etPassword);
        btnRegister = findViewById(R.id.btnRegister);
        btnGoLogin = findViewById(R.id.btnGoLogin);

        db = new DBHelper(this);

        // Register button
        btnRegister.setOnClickListener(v -> {
            boolean success = db.insertUser(
                    etUsername.getText().toString(),
                    etPassword.getText().toString()
            );

            if (success) {
                Toast.makeText(this,
                        "Registration successful",
                        Toast.LENGTH_SHORT).show();

                startActivity(new Intent(MainActivity.this, MainActivity2.class));
            }
        });

        // Go to Login page
        btnGoLogin.setOnClickListener(v -> startActivity(
                new Intent(MainActivity.this, MainActivity2.class)
        ));
    }
}