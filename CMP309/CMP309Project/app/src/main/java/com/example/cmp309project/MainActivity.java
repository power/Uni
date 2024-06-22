package com.example.cmp309project;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.view.MenuItem;
import android.widget.Button;

import android.Manifest;


public class MainActivity extends AppCompatActivity{

    Button recordDay;
    Button prevEntries;
    Button showMap;
    private final int READ_PERMISSISON_CODE = 1;
    private final int WRITE_PERMISSISON_CODE = 2;
    // define our variables
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // set our layout


        if (ActivityCompat.checkSelfPermission(this, Manifest.permission.READ_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED && ActivityCompat.checkSelfPermission(this, Manifest.permission.WRITE_EXTERNAL_STORAGE) != PackageManager.PERMISSION_GRANTED) {
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.READ_EXTERNAL_STORAGE}, READ_PERMISSISON_CODE);
            ActivityCompat.requestPermissions(this, new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE}, WRITE_PERMISSISON_CODE);
        }
            // check whether we have permissions to r/w storage, ask for them if not granted
        recordDay = findViewById(R.id.menu_recordDay);
        prevEntries = findViewById(R.id.menu_showPrevEntries);
        showMap = findViewById(R.id.menu_Showmap);
        // get our button ID's
        recordDay.setOnClickListener(v -> {
            Intent recordDay = new Intent(this, RecordDay.class);
            startActivity(recordDay);
        });

        prevEntries.setOnClickListener(v -> {
            Intent listEntries = new Intent(this, listEntries.class);
            startActivity(listEntries);
        });

        showMap.setOnClickListener(v -> {
            Intent showMaps = new Intent(this, ShowmapActivity.class);
            startActivity(showMaps);
        });
        // set a listener so that if clicked, changes the layout
    }


}