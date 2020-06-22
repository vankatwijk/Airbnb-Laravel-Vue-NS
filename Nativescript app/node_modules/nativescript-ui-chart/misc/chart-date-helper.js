Object.defineProperty(exports, "__esModule", { value: true });
function getCalendarFromDate(date) {
    var calendar = java.util.Calendar.getInstance();
    calendar.setTimeInMillis(date.getTime());
    return calendar;
}
exports.getCalendarFromDate = getCalendarFromDate;
function getDateFromCalendar(calendar) {
    return new Date(calendar.getTimeInMillis());
}
exports.getDateFromCalendar = getDateFromCalendar;
function getCalendarFromMilliseconds(value) {
    var calendar = java.util.Calendar.getInstance();
    calendar.setTimeInMillis(value);
    return calendar;
}
exports.getCalendarFromMilliseconds = getCalendarFromMilliseconds;
