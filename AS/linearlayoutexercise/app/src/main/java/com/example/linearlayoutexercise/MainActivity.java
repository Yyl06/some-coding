package com.example.linearlayoutexercise;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button btnSubmit = findViewById(R.id.buttonClick);
        Button btnCancel = findViewById(R.id.button);

        btnSubmit.setOnClickListener(v -> Toast.makeText(
                MainActivity.this,
                "Data Submitted Successfully",
                Toast.LENGTH_SHORT
        ).show());

        btnCancel.setOnClickListener(v -> Toast.makeText(
                MainActivity.this,
                "Action Canceled",
                Toast.LENGTH_SHORT
        ).show());
    }
}