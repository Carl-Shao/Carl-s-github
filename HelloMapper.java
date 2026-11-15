package com.example.demo.mapper;

import com.example.demo.core.model.Hello;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Options;
import org.apache.ibatis.annotations.Select;

import java.util.List;

//@Mapper
public interface HelloMapper {

//    @Select("SELECT * FROM hello WHERE id = #{id}")
//    Hello findById(Long Id);
//
//    @Select("SELECT * FROM hello")
//    List<Hello> findAll();
//
//    @Insert("INSERT INTO hello(name, age) VALUES(#{name}, #{age})")
//    @Options(useGeneratedKeys = true, keyProperty = "id")
//    int insert(Hello hello);
}
