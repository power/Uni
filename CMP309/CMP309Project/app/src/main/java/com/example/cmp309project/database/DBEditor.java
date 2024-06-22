package com.example.cmp309project.database;

import android.annotation.SuppressLint;
import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;
import android.os.DropBoxManager;
import android.widget.Toast;

import com.example.cmp309project.Info;

import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

public class DBEditor {

    private DBHelper helper = null;
    private final Context context;
    private SQLiteDatabase db;
    public DBEditor(Context a) {
        context = a;
    }

    public void open() {
        helper = new DBHelper(context);
        db = helper.getWritableDatabase();
    }

    // easier to define this here then write it EVERY time we want to r/w to DB
    public void close() {
        helper.close();
    }


    @SuppressLint("SimpleDateFormat")
    public void insert(int rating, String desc) {
        ContentValues cv = new ContentValues();
        Calendar calendar = Calendar.getInstance();
        Date now = calendar.getTime();
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
        String timestamp = simpleDateFormat.format(now);
        cv.put(DBHelper.DATE, timestamp); // get the time at submission
        cv.put(DBHelper.MOOD_RATING, rating);
        cv.put(DBHelper.DESC, desc);
        db.insert(DBHelper.TABLE_NAME, null, cv); // place the values into the table

    }

    public Info fetchInfo() {

        Info info = new Info();

        Cursor cursor = db.rawQuery("Select * from diaryText", null);

        if (cursor.getCount() == 0) {
            return null; // if the table is empty
        } else {
            while (cursor.moveToNext()) { // read the latest line
                info.setId(cursor.getInt((0))); // 1st column
                info.setDate(cursor.getString((1))); // 2nd column etc
                info.setRating(cursor.getInt((2)));
                info.setDesc(cursor.getString((3)));

            }
            return info;
        }
    }

    public void deleteEntry(String id) {
        db.delete(DBHelper.TABLE_NAME, DBHelper.ID + " = " + id, null); // we're using the latest entry although this could be changed to be for whatever entry the user wants?
    }
}