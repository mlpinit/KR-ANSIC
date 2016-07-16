require "minitest/autorun"

class EntabTest < Minitest::Test

  def test_starting_position_and_nth_column
    input_file = "entab_test/four_tabs.txt"
    output_file = "entab_test/four_tabs.result"
    system(".././entab -3 +4 < #{input_file} > #{output_file}")

    output_text = IO.read(output_file)
    expected_output_text = IO.read("entab_test/four_tabs.expected_result")
    assert_equal output_text, expected_output_text
  end

  def test_provided_ints_for_tab_stops
    input_file = "entab_test/provided_ints.txt"
    output_file = "entab_test/provided_ints.result"
    system(".././entab 3 10 16 20 < #{input_file} > #{output_file}")

    output_text = IO.read(output_file)
    expected_output_text = IO.read("entab_test/provided_ints.expected_result")
    assert_equal output_text, expected_output_text
  end

end
