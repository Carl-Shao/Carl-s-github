package com.example.demo;


import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;



@Configuration
public class TimeConfiguration {

    @Bean
    public TimeFormat timeFormat() {
        return new TimeFormat();
    }
}
