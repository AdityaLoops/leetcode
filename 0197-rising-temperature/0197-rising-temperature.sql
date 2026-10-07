# Write your MySQL query statement below
select w.id from Weather w join Weather e on w.recordDate = date_add(e.recordDate, interval 1 day) where w.temperature > e.temperature