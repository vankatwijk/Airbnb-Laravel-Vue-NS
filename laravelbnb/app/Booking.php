<?php

namespace App;

use Illuminate\Database\Eloquent\Model;
use Illuminate\Database\Eloquent\Builder;

class Booking extends Model
{

    protected $fillable = ['from','to'];

    public function bookable()
    {
        return $this->belongsTo(Booking::class);
    }

    public function review(){
        return $this->hasOne(Review::class);
    }

    public function scopeBetweenDates(Builder $query, $from, $to){

        return $query->where('to','>=',$from)->where('from','<=',$to);
    }
}
