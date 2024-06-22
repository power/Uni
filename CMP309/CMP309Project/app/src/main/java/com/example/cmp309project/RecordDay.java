package com.example.cmp309project;

import static com.google.android.material.navigation.NavigationView.*;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.Toast;

import com.example.cmp309project.database.DBEditor;
import com.google.android.material.bottomnavigation.BottomNavigationView;
import com.google.android.material.navigation.NavigationBarItemView;
import com.google.android.material.navigation.NavigationBarView;
import com.google.android.material.navigation.NavigationView;


public class RecordDay extends AppCompatActivity {

    Button submitBtn;
    EditText editData;
    private DBEditor dbManager;
    int mood = 0;

    // define our variables
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_recordday);
        //NavigationBarView bottomNav = findViewById(R.id.bottom_navigation);
        BottomNavigationView bottomNavigationView = findViewById(R.id.bottom_navigation);
        // set our layout
        bottomNavigationView.setOnNavigationItemSelectedListener(new BottomNavigationView.OnNavigationItemSelectedListener() {
            @SuppressLint("NonConstantResourceId")
            @Override
            public boolean onNavigationItemSelected(@NonNull MenuItem item) {
                switch (item.getItemId()) {
                    case R.id.algorithm:
                        return true;
                    case R.id.course:
                        return true;
                    case R.id.profile:
                        return true;
                    default:
                        return true;
                }
            }
        });
        Button submitBtn = findViewById(R.id.recordDay_btn);
        editData = findViewById(R.id.recordDay_editText);
        Button verysadBtn = findViewById(R.id.recordDay_btn_verysad);
        ImageView verysadImg = findViewById(R.id.recordDay_imageView_verysad);
        Button sadBtn = findViewById(R.id.recordDay_btn_sad);
        ImageView sadImg = findViewById(R.id.recordDay_imageView_sad);
        Button alrightBtn = findViewById(R.id.recordDay_btn_alright);
        ImageView alrightImg = findViewById(R.id.recordDay_imageView_alright);
        Button goodBtn = findViewById(R.id.recordDay_btn_good);
        ImageView goodImg = findViewById(R.id.recordDay_imageView_good);
        Button verygoodBtn = findViewById(R.id.recordDay_btn_verygood);
        ImageView verygoodImg = findViewById(R.id.recordDay_imageView_verygood);
        // assign everything on the page
        verysadBtn.setOnClickListener(v -> {
            mood = 1;
            verysadImg.setVisibility(View.VISIBLE);
            sadImg.setVisibility(View.INVISIBLE);
            alrightImg.setVisibility(View.INVISIBLE);
            goodImg.setVisibility(View.INVISIBLE);
            verygoodImg.setVisibility(View.INVISIBLE);
        });
        sadBtn.setOnClickListener(v -> {
            mood = 2;
            sadImg.setVisibility(View.VISIBLE);
            verysadImg.setVisibility(View.INVISIBLE);
            alrightImg.setVisibility(View.INVISIBLE);
            goodImg.setVisibility(View.INVISIBLE);
            verygoodImg.setVisibility(View.INVISIBLE);
        });
        alrightBtn.setOnClickListener(v -> {
            mood = 3;
            alrightImg.setVisibility(View.VISIBLE);
            sadImg.setVisibility(View.INVISIBLE);
            verysadImg.setVisibility(View.INVISIBLE);
            goodImg.setVisibility(View.INVISIBLE);
            verygoodImg.setVisibility(View.INVISIBLE);
        });
        goodBtn.setOnClickListener(v -> {
            mood = 4;
            goodImg.setVisibility(View.VISIBLE);
            sadImg.setVisibility(View.INVISIBLE);
            alrightImg.setVisibility(View.INVISIBLE);
            verysadImg.setVisibility(View.INVISIBLE);
            verygoodImg.setVisibility(View.INVISIBLE);
        });
        verygoodBtn.setOnClickListener(v -> {
            mood = 5;
            verygoodImg.setVisibility(View.VISIBLE);
            sadImg.setVisibility(View.INVISIBLE);
            alrightImg.setVisibility(View.INVISIBLE);
            goodImg.setVisibility(View.INVISIBLE);
            verysadImg.setVisibility(View.INVISIBLE);
        });

        // set listeners for the mood rating so that if clicked, change the picture and set the variable
        submitBtn.setOnClickListener(v -> {
            String data_to_enter = editData.getText().toString();
            if (mood == 0) // if mood hasnt been changed
            {
                Toast.makeText(this, "Please rate your day between 1 & 5", Toast.LENGTH_SHORT).show();
            } else if (data_to_enter.isEmpty()) // or if they havent described their day
            {
                Toast.makeText(this, "Please describe your day", Toast.LENGTH_SHORT).show();
            } else {
                dbManager = new DBEditor(this); // create an instance for the DB
                dbManager.open(); // open it
                dbManager.insert(mood, data_to_enter); // insert our data
                Intent returnToStart = new Intent(RecordDay.this, MainActivity.class);
                startActivity(returnToStart); // return to the main menu
                dbManager.close(); // close the DB
            }
        });

    }
}