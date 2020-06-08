<?php

namespace App\Http\Controllers\Api;

use App\Bookable;
use App\Http\Controllers\Controller;
use Illuminate\Http\Request;
use App\Http\Resources\BookableIndexResource;
use App\Http\Resources\BookableShowResource;

class BookableController extends Controller
{
    public function index(){
        return BookableIndexResource::collection(
            Bookable::all()
        );
    }
    public function show($id){
        return new BookableShowResource( Bookable::findOrFail($id) ); //findOfFail will return 400 error if it can't find
    }
}
