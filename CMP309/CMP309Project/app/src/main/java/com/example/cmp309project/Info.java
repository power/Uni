package com.example.cmp309project;

import java.util.ArrayList;

public class Info {

    int id;
    String date;
    int rating;
    String desc;

    public Info(){}

    public void setId(int id){
        this.id = id;
    }

    public int getId(){
        return this.id;
    }

    public void setDate(String data){
        this.date = date;
    }

    public String getDate(){
        return this.date;
    }

    public void setRating(int rate){
        this.rating = rate;
    }

    public int getRating(){
        return this.rating;
    }

    public void setDesc(String desc){
        this.desc = desc;
    }

    public String getDesc(){
        return this.desc;
    }

    // getters and setters for making life easy(hopefully)
}
