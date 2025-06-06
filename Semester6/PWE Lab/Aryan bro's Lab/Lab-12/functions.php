<?php
session_start();

function checkLogin()
{
    if (!isset($_SESSION['admin_username'])) {
        header("Location: login.php");
        exit();
    }
}

function logout()
{
    session_destroy();
    header("Location: login.php");
    exit();
}
