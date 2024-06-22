package com.example.cmp309project;

import android.app.Dialog;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.RecyclerView;

import com.example.cmp309project.database.DBEditor;

import java.util.ArrayList;

public class listEntries extends AppCompatActivity {
    ArrayList<String> id, date, rating, desc;
    DBEditor db;


//    prevEntriesAdapter adapter;


    Info info;
    // define our variables
    @Override
    protected void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_listentries);
        // set the ui
        db = new DBEditor(this);
        info = new Info();
        // instantiate things
        Button deleteBtn = findViewById(R.id.btn_deleteEntry);
        deleteBtn.setOnClickListener(v -> {
            showPopup();
            //deleteEntry(); // if they click the button that says "delete entry" delete that entry
        });
        displayInfo();
    }

    private void showPopup(){
        Dialog dialog = new Dialog(this);
        dialog.setContentView(R.layout.popup_dialog);
        dialog.show();
    }
    private void deleteEntry() {
        TextView entry_num = findViewById(R.id.et_entry_num);
        String temp_value = String.valueOf(entry_num.getText()); // get the entire value e.g. "Entry Number: 3"
        String[] temp_value_seperated = temp_value.split(":"); // split ^ so that the title is seperate from the value
        db.open(); // open the db
        db.deleteEntry(temp_value_seperated[1]); // delete the entry based on the VALUE not the title
        Toast.makeText(this, "Entry Deleted", Toast.LENGTH_SHORT).show(); // tell the user
        Intent returnToStart = new Intent(listEntries.this, MainActivity.class); // back to the start
        startActivity(returnToStart);
        db.close();
    }
    private void displayInfo() {
        db.open();

        info = db.fetchInfo(); // get the last entry

        if(info == null){
            Toast.makeText(this, "No entries", Toast.LENGTH_SHORT).show();
        }
        else{
            TextView entry_num = findViewById(R.id.et_entry_num);
            TextView date = findViewById(R.id.et_date);
            TextView mood_rating = findViewById(R.id.et_mood_rating);
            TextView desc = findViewById(R.id.et_description);
            // define our titles

            entry_num.setText(entry_num.getText()+Integer.toString(info.getId())); // convert the integer's to strings so they can be handled by TextView
            date.setText(date.getText()+ info.getDate());
            mood_rating.setText(mood_rating.getText()+Integer.toString(info.getRating()));
            desc.setText(desc.getText()+info.getDesc());
            // place the last entry onto the screen
        }

    }
}
