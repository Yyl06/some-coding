package com.example.linearlayout;
import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Link first button from XML to Java
        Button btnClick = findViewById(R.id.buttonClick);

        // Link second button from XML to Java
        Button btnIgnore = findViewById(R.id.button);

        // Button 1 click action
        btnClick.setOnClickListener(v -> Toast.makeText(
                MainActivity.this,
                "Button Click pressed!",
                Toast.LENGTH_SHORT
        ).show());

        // Button 2 click action
        btnIgnore.setOnClickListener(v -> Toast.makeText(
                MainActivity.this,
                "Button Ignore pressed!",
                Toast.LENGTH_SHORT
        ).show());
    }
}
