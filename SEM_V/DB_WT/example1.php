<?php
    //connection to server
    $conn = mysqli_connect('localhost','root','','hospital_mgmt');
    if($conn){
        echo "<br>connected successfully";
    }else{
        echo "<br>connection failed";
        exit();
    } 

    if($_SERVER['REQUEST_METHOD'] == "POST") {
        if(isset($_POST['name']) && isset($_POST['gender']) 
            && isset($_POST['blood-type']) && isset($_POST['contact'])
            && isset($_POST['age'])&& isset($_POST['username'])
            && isset($_POST['password']))
        {
            $name = $_POST['name'];
            $gender = $_POST['gender'];
            $blo0d_type = $_POST['blood-type'];
            $contact = $_POST['contact'];
            $age = $_POST['age'];
            $username = $_POST['username'];
            $password = $_POST['password'];
            
            $q3 = "INSERT INTO PATIENT (name,age,gender,bloodgroup,contactnumber,username,pass_word) values(
            '$name','$age','$gender','$bloodgroup','$contactnumber','$username','$pass_word')";
            $r3 = mysqli_query($conn, $q3);
            if($r3) {
                echo "<br>Data inserted successfully";
                //display inserted data
                echo "<br>RECORD:";
                echo "<br>ID: $pid<br>Name: $pname<br>Age: $age<br>Gender: $gender<br>Bloodgroup: $blood_group<br>Contact No: $contactnumber <br>Username: $username <br>Password: $pass_word";
            }else {
                echo "<br>failed to insert data";
            }
        }
    } else {
        echo "<br>insert failed";
        exit();
    }
    mysqli_close($conn);


    ?>