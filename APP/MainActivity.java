package com.example.myapplication1;
import android.app.AlertDialog;
import android.content.Intent;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonObjectRequest;
import com.android.volley.toolbox.Volley;
import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
public class MainActivity extends AppCompatActivity {
    Button click;
    Button click1;
    public static TextView SolutionData;
    public static TextView SolutionLTime;
    public static TextView PHLTime;
    public static TextView PHLData;
    public static TextView TempTime;
    public static TextView TempData;
    public static TextView MainSolution;
    public static TextView MainSoutionTime;
    public static TextView PHData;
    public static TextView PHTime;
    public static TextView WLD;
    public static TextView WLT;
    public static TextView HumiData;
    public static TextView HumiTime;
    public static final String time = "com.example.myapplication1.time";
    private String field3="";
    ImageView circleColor;
    TextView solutionL1;
    private String solutionL;
    private String ShowTime;
    private String PH_L;
    private String TemperatumeL;
    private  String Humidity;
    private  String PH_M;
    private  String WaterTemperature;
    private RequestQueue mQueue;
    public static int field11;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        click = (Button) findViewById(R.id.ViewData);
        click1=findViewById(R.id.info);
        circleColor=findViewById(R.id.color1);
        SolutionData=findViewById(R.id.S_L_Data);
        SolutionLTime=findViewById(R.id.S_L_Time);
        PHLTime=findViewById(R.id.PH_Time);
        PHLData=findViewById((R.id.PH_Data));
        MainSolution=findViewById(R.id.mainSolutionData);
        MainSoutionTime=findViewById(R.id.mainSolutionTime);
        TempData=findViewById(R.id.temperatureData);
        TempTime=findViewById(R.id.temperatureTime);
        PHData=findViewById((R.id.PHData));
        PHTime=findViewById(R.id.PHTime);
        HumiData=findViewById(R.id.HumidityData);
        HumiTime=findViewById(R.id.HumidityTime);
        WLD=findViewById(R.id.WaterLTData);
        WLT=findViewById(R.id.WaterLTime);
        mQueue = Volley.newRequestQueue(this);
        click1.setOnClickListener(new View.OnClickListener() {
               @Override
                public void onClick(View v) {
                   Intent intent=new Intent(MainActivity.this,Information.class);
                   startActivity(intent);
                }
             });
       click.setOnClickListener(new View.OnClickListener() {
           @Override
            public void onClick(View v) {
               fetchData process = new fetchData();
               process.execute();
               HumiData process1 = new HumiData();
               process1.execute();
               pH process3 = new pH();
               process3.execute();
               pHLevel process4 = new pHLevel();
               process4.execute();
               Temp process5 = new Temp();
               process5.execute();
              WaterLevel process6 = new WaterLevel();
              process6.execute();
               new Handler().postDelayed(new Runnable() {
                   @Override
                   public void run() {
                       click.performClick();
                   }
               }, 5000000);
           }
        });
    }
    public void goToInfo()
   {
       Intent i=new Intent(MainActivity.this,Information.class);
       startActivity(i);
  }
}
