package com.example.cmp309project.database;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DBHelper extends SQLiteOpenHelper {
    public static final String DB_NAME = "diaryUpdatesFinal2.db";
    public static final int DB_VER = 1;
    public static final String TABLE_NAME = "diaryText";
    public static final String ID = "_id";
    public static final String DATE = "date";
    public static final String MOOD_RATING = "moodRating";
    public static final String DESC = "description";

    // define all of our column names as constants to make string concat 10000000x easier
    private static final String CREATE_TABLE =
            "CREATE TABLE " + TABLE_NAME +
                    "(" + ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
                    DATE + " TEXT NOT NULL, " +
                    MOOD_RATING + " INTEGER NOT NULL, " +
                    DESC + " TEXT NOT NULL)";
    // make our table
    public DBHelper(Context context){super(context, DB_NAME, null, DB_VER);}

    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(CREATE_TABLE);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int version1, int version2) {
        db.execSQL("DROP TABLE IF EXISTS " + TABLE_NAME);
        onCreate(db);
    }


}
