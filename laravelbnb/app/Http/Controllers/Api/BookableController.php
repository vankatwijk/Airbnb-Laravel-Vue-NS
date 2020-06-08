<?php

namespace App\Http\Controllers\Api;

use App\Bookable;
use App\Http\Controllers\Controller;
use Illuminate\Http\Request;

class BookableController extends Controller
{
    public function index(){
        return Bookable::all();
    }
    public function show($id){
        return Bookable::findOrFail($id); //findOfFail will return 400 error if it can't find
    }
}
