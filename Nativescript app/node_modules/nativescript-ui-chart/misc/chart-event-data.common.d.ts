import { EventData } from "tns-core-modules/data/observable";
export declare class ChartEventData implements EventData {
    /**
    *Returns the name of the event that has been fired.
    */
    eventName: string;
    /**
    * The object that fires the event.
    */
    object: any;
    /**
    * Gets the index of the data point in the series to which the event relates.
    */
    pointIndex: number;
    /**
    * Gets the selected series to which the event relates.
    */
    series: any;
    /**
    * TKChartData values with additional event related data
    */
    pointData: any;
}
export declare class TrackballSelection implements EventData {
    /**
    *Returns the name of the event that has been fired.
    */
    eventName: string;
    /**
   * The object that fires the event.
   */
    object: any;
    selection: Array<any>[];
}
export declare class TrackballCustomContentData extends ChartEventData {
    /**
     * The custom trackball content for the provided data point within the provided series.
     */
    content: string;
    /**
     * The index of the series within the series collection of the current chart.
     */
    seriesIndex: number;
}
