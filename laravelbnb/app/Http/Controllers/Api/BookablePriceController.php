<?php

namespace App\Http\Controllers\Api;

use App\Bookable;
use Carbon\Carbon;
use Illuminate\Http\Request;
use App\Http\Controllers\Controller;

class BookablePriceController extends Controller
{
    /**
     * Handle the incoming request.
     *
     * @param  \Illuminate\Http\Request  $request
     * @return \Illuminate\Http\Response
     */
    public function __invoke($id, Request $request)
    {
        $bookable = Bookable::findOrFail($id);

        $date = $request->validate([
            'from' => 'required|date_format:Y-m-d',
            'to' => 'required|date_format:Y-m-d|after_or_equal:from'
        ]);

        $days = (new Carbon($date['from']))->diffInDays(new Carbon($date['to'])) +1;
        $price = $days * $bookable->price;

        return response()->json([
            'data' => $price,
            'breakdown' => [
                $bookable->price => $days
            ]
        ]);
    }
}
