package com.example.bui.btcanhanso7buiducthang;

import android.content.Intent;
import android.net.Uri;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.MediaController;
import android.widget.VideoView;

public class MainActivity extends AppCompatActivity {
    private VideoView videoView;
    private Button btnPlay;
    private MediaController mediaController;
    private Button btnPlayByURL;
    private EditText txtURL;
    private Button btnMusic;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        btnPlay = (Button) findViewById(R.id.button);
        videoView = (VideoView) findViewById(R.id.videoView);
        btnPlayByURL = (Button) findViewById(R.id.button2);
        btnMusic = (Button) findViewById(R.id.button3);
        txtURL = (EditText) findViewById(R.id.textView);
        mediaController = new MediaController(this);
    }

    public void videoPlay(View view){
        String videoPath = "android.resource://".concat(getPackageName()).concat("/raw/").concat(String.valueOf(R.raw.tom));
        Log.i("Path:",videoPath);
        Uri uri = Uri.parse(videoPath);
        videoView.setVideoURI(uri);


        videoView.setMediaController(mediaController);
        mediaController.setAnchorView(videoView);
        videoView.start();
    }

    public void videoPlayByURL(View view) {
        String url = txtURL.getText().toString();
        videoView.setVideoPath(url);
        videoView.setMediaController(mediaController);
        mediaController.setAnchorView(videoView);
        videoView.start();

    }

    public void music(View view){
        Intent intent = new Intent(this, MusicActivity.class);
        startActivity(intent);
    }
}