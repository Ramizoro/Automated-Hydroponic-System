package com.example.myapplication1;
import android.os.AsyncTask;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
public class Temp extends AsyncTask<Void,Void,Void> {
    String data ="";
    @Override
    protected Void doInBackground(Void... voids) {
        try {
            URL url = new URL("https://api.thingspeak.com/apps/thinghttp/send_request?api_key=1AOXHS2IED2IWI3I\n");
            HttpURLConnection httpURLConnection = (HttpURLConnection) url.openConnection();
            InputStream inputStream = httpURLConnection.getInputStream();
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
            data = bufferedReader.readLine();
        } catch (MalformedURLException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } 
        return null;
    }@Override
    protected void onPostExecute(Void aVoid) {
        super.onPostExecute(aVoid);
        if(data.length()<2)
            MainActivity.TempData.setText(this.data);
    }
}