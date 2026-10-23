package com.example.demo;


import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.ResponseBody;

@Controller
public class TimeController {

    @Autowired
    private TimeFormat timeFormat;

    @GetMapping("/time")
    @ResponseBody
    public String time() {
        return timeFormat.format();
    }
}
